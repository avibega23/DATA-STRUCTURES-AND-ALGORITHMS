class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                // If the current digit is less than 9, just increment it and return the result
                digits[i]++;
                return digits;
            }
            // Otherwise, set the current digit to 0 and continue to the next digit
            digits[i] = 0;
        }

        // If we exit the loop, it means all the digits were 9 (e.g., 999 -> 1000)
        digits.insert(digits.begin(), 1); // Add 1 at the beginning
        return digits;
    }
};