int atoi(const char* str)
{
    int a=0, i, j, sum = 0;
    for(i = 0; str[i]!='\0';i++)
    {
        a = str[i]-48;
        sum=sum*10+a;
    }

    return sum;
}