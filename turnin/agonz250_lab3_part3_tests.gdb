# Test file for "Lab3_BitManip"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

#0
test "PINA: 0x00, PINB: 0x00 => PORTC: 0x20"
# Set inputs
setPINA 0x00
setPINB 0x00
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x40
# Check pass/fail
checkResult


#1
test "PINA: 1 => PORTC: 0x60"
# Set inputs
setPINA 1
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x60
# Check pass/fail
checkResult

 
#2
test "PINA: 2 => PORTC: 0x60"
# Set inputs
setPINA 2
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x60
# Check pass/fail
checkResult


#3
test "PINA: 3 => PORTC: 0x70"
# Set inputs
setPINA 3
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x70
# Check pass/fail
checkResult


#4
test "PINA: 4 => PORTC: 0x70"
# Set inputs
setPINA 4
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x70
# Check pass/fail
checkResult

#5
test "PINA: 5 => PORTC: 0x38"
# Set inputs
setPINA 5
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x38
# Check pass/fail
checkResult

#6
test "PINA: 6 => PORTC: 0x38"
# Set inputs
setPINA 6
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x38
# Check pass/fail
checkResult

#7
test "PINA: 7 => PORTC: 0x3C"
# Set inputs
setPINA 7
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x3C
# Check pass/fail
checkResult


#8
test "PINA:8 => PORTC: 0x3C"
# Set inputs
setPINA 8
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x3C
# Check pass/fail
checkResult


#9
test "PINA: 9 => PORTC: 0x3C"
# Set inputs
setPINA 9
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x3C
# Check pass/fail
checkResult


#10
test "PINA: 10 => PORTC: 0x3E"
# Set inputs
setPINA 10
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x3E
# Check pass/fail
checkResult

#11
test "PINA: 11 => PORTC: 0x3E"
# Set inputs
setPINA 11
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x3E
# Check pass/fail
checkResult


#12
test "PINA: 12 => PORTC: 0x3E"
# Set inputs
setPINA 12
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x3E
# Check pass/fail
checkResult


#13
test "PINA: 13 => PORTC: 0x3F"
# Set inputs
setPINA 13
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x3F
# Check pass/fail
checkResult


#14
test "PINA: 14 => PORTC: 0x3F"
# Set inputs
setPINA 14
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x3F
# Check pass/fail
checkResult


#15
test "PINA: 15 => PORTC: 0x3F"
# Set inputs
setPINA 15
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x3F
# Check pass/fail
checkResult


#Special Case
test "PINA: 0x3F => PORTC: 0xBF"
# Set inputs
setPINA 0x3F
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0xBF
# Check pass/fail
checkResult




# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
