### ExecEngine Feedback:
#### General / DevOps Feedback
- Excellent file structure, good work splitting up the different header files into folders to make your repo easier to navigate. 
  - However, note that it's standard practice to split up the header files (.hpp) declaring your classes / functions and seperate implementation files (.cpp) which actually defines them. This improves build times, as changing a header implementation only requires one file to be recompiled (where the header is actually defined), rather than having to recompile each file the header is included in.
  - Additionally, your makefile doesn't track header file changes, meaning that if you do change a header file, `make` won't notice this automatically and you'd need to `make clean` and `make` the entire project again (see https://stackoverflow.com/a/30142139 on how to avoid this)
  - `[nitpick]` Your `.gitignore` file seems to exclude a lot more than it needs to (why do you have a rule for Fortran modules :joy:), but doesn't actually ignore some generated files like your `lexer.yy.cpp` or `parser.tab.*`. 

- You have *a lot* of compiler warnings when building your project. It's best to try and address these, or (if you know what you're doing) to explicitly tell the compiler to ignore them (for example using the [`[[maybe_unused]]` attribute](https://en.cppreference.com/w/cpp/language/attributes/maybe_unused))
- Excellent commit messages and good use of branches to add features.
- Great work writing lots of your own custom test-cases, I'm sure this was very helpful in catching bugs.

#### Code Feedback
- It's impressive you went with the writing your own parser approach (and even more impressive that you scored so well doing this). Unfortunately, the C grammar is quite complex, and your parser did not fully capture it, making it the leading cause of your unseen test failures :sob: (21 failures due to parse error alone, accounting ~51% of errors). With a project like this, especially when you ended up supporting so many features, it would've been best to switch to the standard (ANSI-C), trimming down any unnecessary parts, rather than continuing to build on your own version.
  - There are issues with your operator precedence that may have caused you to loose other marks on some of the hidden testcases. For example, relation operators (`>`, `<`, etc.) have a higher precedence that bitwise operators (`&`, `|`, `^` - note that these don't even have the same precedence between each other), but in your grammar they all have equal precedence (see the [C Operator Precedence](https://en.cppreference.com/w/cpp/language/operator_precedence))
  - There seems to be a semantic error for `case` statements. You always allocate a new `Block` (which represents a scope) for case statements:
  ```c++
  CASES
	: CASE EXPR ':' BODY 							{ $$ = new case_statement($2, new Block($4)); }
	| DEFAULT ':' BODY 								{ $$ = new default_statement( new Block($3)); }
  ```
  However this is not the correct behaviour - case statements share the same scope, and new blocks should only be created if the case statement has scoped blocks succeeding it, i.e.
  ```c
  int f(int x) {
    int y = 0;
    switch(x) 
    {
        case 0:
            y += 3; // No new scope here
        case 1:
        { // New scope here because of {}
            int y;
            y += 5; // Has no impact on return value (refers to y in new scope)
        }
            y++;
    }
    return y;
  }
  ```
  - Nice work implementing the "lexer hack" to handle `typedef`s!

- I like that your `Node` class doesn't have any member variables, and declares `print` as a pure virtual function that your derived classes have to implement. However, ideally all of the other methods in `Node` (`getId`, `getValue`, etc.) should also be made pure virtual (`=0`), (especially `riscv_asm`), or if they aren't implemented by every derived class, should be only defined in those relevant subclasses, and store pointers to those subclasses rather than general `Node*` where relevant. As they are, these methods don't even produce a runtime error (with the exception of `getValue`), meaning that you could be calling `getId` on a completely invalid derived type and not notice immediately.
  - I'm not sure why you include a `std::map<std::string, std::vector<std::string>>& bindings` in your `riscv_asm` method, could this not be part of `Helper& helper`? For `std::string datatype`, I think it would be better to define an overload of `riscv_asm` which takes it, and one which doesn't, so you can be more explicit about the `Node` constructs which rely on type information and those which don't. Something like the following could be good:
  ```c++
  enum class Type; // Encodes the types as an enum class rather than a string

  class Node {
    virtual void riscv_asm(std::ostream& dst, Helper& helper, const std::string& destReg) =0; // Default implementation (for derived constructs that require type info this could give a runtime error when called)
    virtual void riscv_asm(std::ostream& dst, Helper& helper, const std::string& destReg, [[maybe_unused]] Type type) {
        // Note: up to you to decide if simply logging a warning is sufficient or if calling the type-specialised version on a class which doesn't implement it should result in a runtime error
        std::cerr << "[Warning] Calling type-specialised riscv_asm on class which doesn't implement it" << std::endl;
        riscv_asm(dst, helper, destReg);
    }
  };
  ```
  This approach isn't perfect as ideally, a class which derives from `Node` has the requirement to implement the non-type-specialised version of `riscv_asm`, and never needs to implement the type-specialised version. Ideally, derived classes should implement one or the other, shifting all the run-time errors in the implementation above to compile-time (always preferable). There might be a way to capture these semantics using some new C++20 features like [`concepts`](https://en.cppreference.com/w/cpp/language/constraints), but I wasn't able to easily find a way to do this, so it's possible that the implementation above is the best you could do at the moment.
  - I'm not sure why you've added the `evaluate` method to your compiler, this isn't really relevant for the purposes of this coursework. You've also implemenented it for many of your derived classes, but never actually use it anywhere meaningful in your program.
  - `[nitpick]` You should have made the `destReg` parameter in `riscv_asm` a `const std::string&` rather than a `std::string`. In this case I'm assuming that your `destReg` strings are only 2 characters so it's not that much memory to copy (although it would be more than a const string reference - pointer, when considering the other private member variables of `std::string`), but in general it's always good practice to pass these container types which can be expensive to copy by const reference instead of value. This is a bigger issue for the return type of `getId()`, as this could lead to copying an aribtrarily long variable name which would significantly slow down your code.
  - In general, avoid statements like `typedef const Node *NodePtr;`. Although it ensures you don't accidentally forget a `const` somewhere (although you'd get a compiler error if you do this), aliasing `const Node*` as `NodePtr` doesn't save you particularly many characters, and only obfuscates your code. It might be worth it specifically for `typedef std::vector<NodePtr> List` as that name is starting to get long, but it's still debatable in that case (and I'd argue that the name `List` isn't descriptive enough). Similarly, I don't think the `init_list` and `concat_list` helper functions are adding any value.

- You use `std::string`s instead of enums in many places, leading to quite unsafe code - especially for `getClass` and `getType`. You even seem to have created an `enum _Types` (which should be an `enum class` - see [why](https://stackoverflow.com/a/18335862)) which is perfect for this, but don't really use it to it's full potential, instead converting it to a string. Sometimes you also don't throw a runtime error when given an invalid value, but rather return a value indicating failure. For example, consider the following function:
  ```c++
  std::string get_loop_labels(std::string where){
    if (where == "Start"){
        return loop_start.back();
    }
    else if (where == "End"){
        return loop_end.back();
    }
    else if (where == "Update"){
        return loop_update.back();
    }
    else{
        return "invalid location to jump";
    }
  }
  ```
  This is quite error prone, as even a slight typo such as calling `get_loop_lables("start")` would quitely return `"invalid location to jump"`, which you might not even notice (although you'd probably get an assembler error). It would be much safer to either have seperate methods for each of the loop labels, or pass in an enum class which defines the 3 possibilities, and calling `exit(1)` if one of these values isn't matched (along with the appropriate error message). If you do want to have the possibility of failure, it would be much safer to return a `std::optional<std::string>>` (see [here](https://en.cppreference.com/w/cpp/utility/optional)), which would allow you to safely perform checks on the returned value, and even throw if you ever accidentally use the result of the function when it's invalid. Your loop label vectors could also contain this optional type, meaning that you could use the null value for the update label in while loops, rather than relying on the string `"None"` to replicate this behaviour. This would be a much nicer version of implementing the same semantics:
  ```c++
  enum class LoopLabel {
    START,
    END,
    UPDATE
  };

  const std::optional<std::string>& GetLoopLabels(LoopLabel where) {
    switch (where) { // compiler will warn you if you miss any cases here
        case LoopLabel::START:
            return loop_start.back();
        case LoopLabel::END:
            return loop_end.back();
        case LoopLabel::UPDATE:
            return loop_update.back();
    }
    std::cerr << "Unexpected loop label (should be impossible)" << std::endl;
    exit(1);
  }
  ``` 
  An even better solution would've been to have a data `struct` tying all of these loop labels together:
  ```c++
  struct LoopLabel {
    std::string start;
    std::string end;
    std::optional<std::string> update; // While loop doesn't have update label
  };

  class Helper {
  private:
    // ...
    std::vector<LoopLabel> loop_labels;
  public:
    // ...
    void EnterLoop(const std::string& start, const std::string& end, const std::optional<std::string>& update = {}) {
        // Constructs LoopLabel object in-place (more efficient - eliminates need to call copy/move constructor)
	// Note that this will still need to make copies of all the labels when constructing the LoopLabel instance, it just won't need to copy the instance itself. If you didn't need to use the labels passed into this function elsewhere you could always pass them in by r-value reference instead (which would now allow you to use a move instead of a copy when constructing the LoopLabel instance)
        loop_labels.emplace_back(start, end, update);
    }

    void ExitLoop()
    {
        if (loop_labels.empty()) {
            std::cerr << "Tried to exit loop when there are no loops" << std::endl;
            exit(1);
        }
        loop_labels.pop_back();
    }

    const LoopLabel& GetLoopLabels() const { return loop_labels.back(); }
  };
  ```
  This ensures that the loop start, end and update labels cannot get out of sync with each other (which is a risk in your code), and also gives you a very clean syntax when trying to access loop labels, i.e.
  ```c++
  void Continue::riscv_asm(std::ostream& dst, Helper& context, ...) {
    const auto& labels = context.GetLoopLabels();
    const std::string& target = labels.update.value_or(labels.start) // sets target to labels.update if it's defined, otherwise labels.start
    dst << "beq zero, zero, " << target << std::endl;
  }
  ```
  Hopefully you can see where these sort of concepts could be useful in other parts of your code to help make things safer :smile:!
   

- You use `std::map`s in many places where you should actually be using `std::unordered_map`s. `std::map`s are implemented as red-black binary trees, meaning that insertion and element lookup take $O(\log{n})$, whilst `std::unordered_map`s are implemented as hash tables, so these same operations only take $O(1)$ time (amortised in the case of insertion).
  - `[nitpick]` You use the `.count` method to check if your maps contain a particular element. While works fine, you should ideally use `.contains` instead (particularly since you're already compiling under C++20 which includes it).

- Your `Helper` class does a lot of really smart things to make your life easier, although I was a little surprised to see that you rely on a fixed stack size for your functions (128 bytes == 32 words). Although this is probably sufficient for most functions you need to compile, it's definitely possible for you to run out of space, an ideal approach would've been to compute how much memory you need as you build up your AST and use this value to decrement your stack. It's good to see that you did consider the possibility of running out of memory, and produce an appropriate runtime error when you do.
  - Your class has some `protected` members, as well as a `virtual` destructor, even though no class inherits from `Helper`. It would've been better to declare these members `private`. In general it's bad practice to have `protected` members - see [here](https://stackoverflow.com/a/3933120).  
  - `[nitpick]` I think `Helper` isn't the best name for your compiler context, as it's a bit too generic, I find something like `Context` would be better. You could even split your helper class into a `LabelManager`, `StackManager`, etc. calling the overall class `ContextManager` - this might be ideal as your class is quite large.

- `[nitpick]` In general, it's better to put `private` members of a class at the bottom of a class definition and `public` members at the top. This is because you usually want the most relevant information at the top of a file (since we read top down) - and for a class this is the public interface, since as a user of the class you don't really care about the implementation details.
- `[nitpick]` In general, classes (in C++) are named using `UpperCamelCase`. You seem to have a mix of this, `snake_case`, `Upper_Snake_Case` and `alllowercase` - try to be consistent with your naming approach for all classes in a project.
- `[nitpick]` Using `#pragma once` instead of `#ifndef ... #define ... #endif` is better for header guards as it is less prone to manual error.

#### Overall
You passed 161 / 202, giving you an overall score of 80%, with a seen to unseen split as follows:
- 87 / 87 seen (100%)
- 74 / 115 unseen (64%)

Although a lot of the feedback that I've provided here is constructive, your compiler is very impressive, and you should both be incredibly proud of your results for this coursework, passing 100% of seen testcases is no small feat so amazing job to both of you -- in fact no other group from this year managed to achieve this. It's a shame that your parser cost you so many marks, I really think you both deserve more, but keep in mind that your overall score is still extremely high relative to the rest of the cohort so great work! I'm sure you both learnt a lot from this project, and I hope that the feedback above can give you some ideas on improving your software engineering skills even further :rocket::moon: .
