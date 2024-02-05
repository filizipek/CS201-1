# Phone Usage Billing System

This C++ program is designed to calculate the total cost of phone usage based on various factors such as minutes, SMS, and internet usage. The program takes inputs for local and international phone usage and calculates the associated costs. It also provides feedback on whether the user has exceeded their package limit.

## Usage Instructions

1. **Compile and Run:**
   - Compile the program using a C++ compiler.
   - Run the executable to start the program.

2. **Input Prompt:**
   - The program will prompt you to enter usage details for local and international phone usage separately.
   - For each type of phone usage (local or international), enter the number of minutes, SMS, and MBs used, along with additional packages for calls, SMS, and internet.

3. **Cost Calculation:**
   - The program calculates the total cost based on the provided usage details and package limits.
   - The cost is determined by considering the base price, additional package prices, and rates for exceeding the package limits.

4. **Result Display:**
   - The program displays the total cost of phone usage and provides feedback on whether the user has exceeded their package limits.
   - If the cost is equal to the base price, it indicates that the user did not exceed their package. If the cost is between the base price and twice the base price, it indicates exceeding the package. If the cost is more than twice the base price, a suggestion to change the package is provided.

## Functions

1. **inputCheck:**
   - Validates that input values are non-negative.

2. **getInputs:**
   - Takes user inputs for minutes, SMS, MBs, and additional packages for calls, SMS, and internet.

3. **costCalculate:**
   - Calculates the total cost based on usage details, package limits, and pricing information.

4. **displayResults:**
   - Displays the total cost of phone usage and provides feedback based on the calculated cost.

## Main Function (main):

- The `main` function initializes variables for local and international phone usage.
- It calls the `getInputs` function for local and international usage separately.
- The `costCalculate` function is then called to calculate the costs for both local and international usage.
- Finally, the `displayResults` function is used to display the results for both types of phone usage.

Feel free to explore, modify, and adapt this program according to your needs. If you have any questions or suggestions, please reach out to the program's author, Filiz İpek Oktay, who created this program on 28.03.2023.
