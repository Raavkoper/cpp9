echo "SUBJECT TESTS\n"

echo "Expression: 8 9 * 9 - 9 - 9 - 4 - 1 +, Answer should be: 42"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo "\nExpression: 7 7 * 7 -, Answer should be: 42"
./RPN "7 7 * 7 -"
echo "\nExpression: 1 2 * 2 / 2 * 2 4 - +, Answer should be: 0"
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo "\nExpression: (1 + 1), Answer should be: Error"
./RPN "(1 + 1)"

