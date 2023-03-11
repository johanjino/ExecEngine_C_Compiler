#!/bin/bash

# Author : Johan Jino (@johanjino)
# Year   : 2023


# USEAGE:
# ./test_single.sh {folder_name}/{file_name_without_".c"}



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


fail_testcase() {
    echo -e "\t> ${1}"
}

arg=$1
prefix="compiler_tests/"
suffix="_driver.c"

DRIVER="${prefix}${arg}${suffix}"
TO_ASSEMBLE="${DRIVER%_driver.c}.c"
LOG_PATH="${TO_ASSEMBLE//\//_}"
LOG_PATH="./bin/output/${LOG_PATH%.c}"

echo "${TO_ASSEMBLE}"

OUT="${LOG_PATH}"
rm -f "${OUT}.s"
rm -f "${OUT}.o"
rm -f "${OUT}"
./bin/c_compiler -S "${TO_ASSEMBLE}" -o "${OUT}.s" 2> "${LOG_PATH}.compiler.stderr.log" > "${LOG_PATH}.compiler.stdout.log"
if [ $? -ne 0 ]; then
    fail_testcase "Fail: see ${LOG_PATH}.compiler.stderr.log and ${LOG_PATH}.compiler.stdout.log"
    exit
    fi

riscv64-unknown-elf-gcc -march=rv32imfd -mabi=ilp32d -o "${OUT}.o" -c "${OUT}.s" 2> "${LOG_PATH}.assembler.stderr.log" > "${LOG_PATH}.assembler.stdout.log"
if [ $? -ne 0 ]; then
    fail_testcase "Fail: see ${LOG_PATH}.assembler.stderr.log and ${LOG_PATH}.assembler.stdout.log"
    exit
fi

riscv64-unknown-elf-gcc -march=rv32imfd -mabi=ilp32d -static -o "${OUT}" "${OUT}.o" "${DRIVER}" 2> "${LOG_PATH}.linker.stderr.log" > "${LOG_PATH}.linker.stdout.log"
if [ $? -ne 0 ]; then
    fail_testcase "Fail: see ${LOG_PATH}.linker.stderr.log and ${LOG_PATH}.linker.stdout.log"
    exit
fi

spike pk "${OUT}" > "${LOG_PATH}.simulation.log"
if [ $? -eq 0 ]; then
    echo -e "\t> Pass"

else
    fail_testcase "Fail: simulation did not exit with exit-code 0"
fi


