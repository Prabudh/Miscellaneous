/*
iWriting programming interview questions hasn't made me rich. Maybe trading Apple stocks will.
Suppose we could access yesterday's stock prices as a list, where:

The indices are the time in minutes past trade opening time, which was 9:30am local time.
The values are the price in dollars of Apple stock at that time.
So if the stock cost $500 at 10:30am, stock_prices_yesterday[60] = 500.

Write an efficient function that takes stock_prices_yesterday and returns the best profit I could have made from 1 purchase and 1 sale of 1 Apple stock yesterday.

For example:

  stock_prices_yesterday = [10, 7, 5, 8, 11, 9]

get_max_profit(stock_prices_yesterday)
# returns 6 (buying for $5 and selling for $11)
*/

void findTheMaxProfit(int* stock,int size)
{
int min = 100000;
int max = 0;
int maxDiff = 0;

for(int i = 0 ; i < size; i++)
{
    if(stock[i]<min)
       min = stock[i];
    
    if((stock[i]-min)>0)
    {   
     if(maxDiff<(stock[i]-min))
       maxDiff = stock[i] - min;
    }

}

printf("Maximum stock profit = %d\n",maxDiff);

}

int main()
{
int stock_prices[] = {10, 7, 5, 8, 11, 9};
findTheMaxProfit(stock_prices,6);
}
