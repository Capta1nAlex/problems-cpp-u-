Alex is studying in the fifth grade and is going to be a meteorologist. Alex recently started a diary, where he wrote the daily temperature in his own town. Alex found the historical data for the past several hundred years, which means that he has a lot of data. Alex asks you to write a program that calculates the average temperature during k consecutive days, and he needs these values for the entire observation period:
Average temperature from 1-st till k-th day
Average temperature from 2-nd till (k + 1)-th day and so on until he has data.

And after all these calculated values Alex needs only two numbers - the minimum and maximum values. Help Alex and write the program for him.

Input data
First line contains two integers n and k - the number of temperature measurements and the number of days to calculate the average temperature (1 ≤ k ≤ n ≤ 10^5). Next line contains n integers - the temperature measurements. Each of these numbers is in the range (-100, 100).

Output data
Print two lines that contains minimum and maximum average temperature, calculated on segments of size k. Round the answer to the nearest integer.

