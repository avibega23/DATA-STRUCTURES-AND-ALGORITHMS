if((num&(1<<i-1))==0)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << 1 << " ";
        }
        
        num = num|(1<<i-1);
        cout << num << " ";
        
        num = num& ~(1<<i-1);
        
        cout << num << " ";