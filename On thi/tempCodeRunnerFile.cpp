}

void odd(int i)
{
    if (c[i - 1] != 0)
    {
        l[i] = c[i - 1] + 1;
    }
    else
        l[i] = 1;
    if (l[i - 1] != 0)
    {
        c[i] = l[i - 1] + 1;
    }
}
