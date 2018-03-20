#include <iostream>

using namespace std;

template <typename V>
class Map
{
    int arr[10];
    MapNode<V>** buckets;
    int tableSize;//primeno
    int size;
    Map()
    {

    }
    V get(char* key)
    {
        int bucketIndex=getBucketIndex(key);
        MapNode<V>* head=buckets[bucketIndex];
        if(head==NULL)
            return 0;
        MapNode<V>* temp=head;
        while(temp!=NULL)
        {
            if(strcmp(temp->key,key)==0)
            {
                return temp->value;
            }
            temp=temp->next;
        }

    }

    int getSize()
    {
        return size;
    }
    int getBucketIndex(char* key)
    {
        long hashCode=0;
        int len=strlen(key);
        int factor=1;
        for(int i=len-1;i>=0;i--)
        {

            factor*=31;
        }
    }
};


int main()
{
    return 0;
}
