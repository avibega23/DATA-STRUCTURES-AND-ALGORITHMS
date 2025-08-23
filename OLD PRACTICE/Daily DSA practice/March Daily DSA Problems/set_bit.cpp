int setBit(int n) {
    // Write Your Code here
    int i = 0;
    int temp = n;
    while(temp!=0)
    {
        if(temp%2==0)
        {
            break;
        }
        i++;
        temp/=2;
    }
    n = (1<<i)|n;
    return n;
}

int setBit(int n) {
    // Write Your Code here
    return n|(n+1);
}