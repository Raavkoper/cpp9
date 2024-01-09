echo "SUBJECT TESTS\n"

echo "Expression: 8 9 * 9 - 9 - 9 - 4 - 1 +, Answer should be: 42"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo "\nExpression: 7 7 * 7 -, Answer should be: 42"
./RPN "7 7 * 7 -"
echo "\nExpression: 1 2 * 2 / 2 * 2 4 - +, Answer should be: 0"
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo "\nExpression: (1 + 1), Answer should be: Error"
./RPN "(1 + 1)"

echo "\nOTHER TESTS\n"

echo "Expression: 1 2 + 3 4 + * 5 - 6 7 - / 8 9 + 10 - *, Answer should be: -112"
./RPN "1 2 + 3 4 + * 5 - 6 7 - / 8 9 + 10 - *"

echo "\nExpression: 7 2 + 4 3 * /, Answer should be: 0.75"
./RPN "7 2 + 4 3 * /"

echo "\nExpression: 3 5 * 8 2 / + 1 -, Answer should be: 18"
./RPN "3 5 * 8 2 / + 1 -"

echo "\nExpression: 8 6 2 - 4 1 + / *, Answer should be: 6.4"
./RPN "8 6 2 - 4 1 + / *"