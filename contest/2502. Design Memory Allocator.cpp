class Allocator {

    int arr[1000]{0};
    int space;
public:
    Allocator(int n) {
        this->space = n;
    }
    
    int allocate(int size, int mID) {
        int spaceFound = 0;
        int spaceStart = -1;
        for(int i = 0; i < space; ++i)
        {
            if(arr[i] == 0)
                ++spaceFound;
            else
                spaceFound = 0;
            

            if(spaceFound == size)
            {
                spaceStart = i + 1 - size;
                break;
            }
        }
        if(spaceStart < 0)
            return -1;
        
        for(int i = spaceStart ; i <  spaceStart + size; ++i)
        {
            arr[i] = mID;
        }

        return spaceStart;
    }
    
    int free(int mID) {
        int freed = 0;
        for(int i = 0; i < space; ++i)
        {
            if(arr[i] == mID)
            {
                arr[i] = 0;
                ++freed;
            }
                
        }
        return freed;
    }
};