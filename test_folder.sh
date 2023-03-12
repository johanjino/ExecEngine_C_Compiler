#!/bin/bash

# Author : Modified by @alvi-codes using the 'test.sh' written by @Jpnock
# Year   : 2023

# To use:
# ./test_folder.sh {folder_name}

make clean

set -uo pipefail
shopt -s globstar

make bin/c_compiler
if [[ "$?" -ne 0 ]]; then
    echo "Build failed.";
    exit;
fi

mkdir -p bin
mkdir -p bin/output

arg=$1

TOTAL=0
PASSING=0

fail_testcase() {
    echo -e "\t> ${1}"
}

for DRIVER in compiler_tests/${arg}/*_driver.c; do
    (( TOTAL++ ))

    TO_ASSEMBLE="${DRIVER%_driver.c}.c"
    LOG_PATH="${TO_ASSEMBLE//\//_}"
    LOG_PATH="./bin/output/${LOG_PATH%.c}"

    echo "${TO_ASSEMBLE}"

    OUT="${LOG_PATH}"
    rm -f "${OUT}.s"
    rm -f "${OUT}.o"
    rm -f "${OUT}"
    timeout --foreground 5s ./bin/c_compiler -S "${TO_ASSEMBLE}" -o "${OUT}.s" 2> "${LOG_PATH}.compiler.stderr.log" > "${LOG_PATH}.compiler.stdout.log"
    if [ $? -ne 0 ]; then
        fail_testcase "Fail: see ${LOG_PATH}.compiler.stderr.log and ${LOG_PATH}.compiler.stdout.log"
        continue
    fi

    timeout --foreground 5s riscv64-unknown-elf-gcc -march=rv32imfd -mabi=ilp32d -o "${OUT}.o" -c "${OUT}.s" 2> "${LOG_PATH}.assembler.stderr.log" > "${LOG_PATH}.assembler.stdout.log"
    if [ $? -ne 0 ]; then
        fail_testcase "Fail: see ${LOG_PATH}.assembler.stderr.log and ${LOG_PATH}.assembler.stdout.log"
        continue
    fi

    timeout --foreground 5s riscv64-unknown-elf-gcc -march=rv32imfd -mabi=ilp32d -static -o "${OUT}" "${OUT}.o" "${DRIVER}" 2> "${LOG_PATH}.linker.stderr.log" > "${LOG_PATH}.linker.stdout.log"
    if [ $? -ne 0 ]; then
        fail_testcase "Fail: see ${LOG_PATH}.linker.stderr.log and ${LOG_PATH}.linker.stdout.log"
        continue
    fi

    timeout --foreground 5s spike pk "${OUT}" > "${LOG_PATH}.simulation.log"
    if [ $? -eq 0 ]; then
        echo -e "\t> Pass"
        (( PASSING++ ))
        
    else
        fail_testcase "Fail: simulation did not exit with exit-code 0"
    fi
done

printf "\nPassing %d/%d tests in \"%s\" folder! \n" "${PASSING}" "${TOTAL}" "${arg}"

source test_parsing.sh
