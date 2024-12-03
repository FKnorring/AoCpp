# Intuiton (Part 1)

My initial thoughts for this problem is to simply subtract the first two numbers of each line, if the result is negative, all proceeding numbers needs to be increasing, if the result is positive, all proceeding numbers needs to be decreasing. If the result is 0, the line can instantly be discarded. If the line is valid, the result is incremented by 1. Then for every number regardless if the line is increasing or decreasing no abs(number - next number) can be greater than 3.

## Hurdles

No hurdles for this problem. I can used what i learned from parsing in the previous problem to solve this one.

# Intuition (Part 2)

This problem seems like it can be solved by being greedy, skipping the first time a line becomes unsafe. The issue with this is the either the first or second number might need to be skipped/removed which might change the "direction" e. g. the line being increasing or decreasing.