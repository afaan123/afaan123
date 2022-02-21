#include<iostream>
#define buffer_size 5
using namespace std;
char item_consumed,item_produced;
char buffer[buffer_size]={'0','0','0','0','0'};
int in=0,out=0,empty=buffer_size;
void produce()
{
    cout<<"Enter the item to be produced: ";
    cin>>item_produced;
  if(in==buffer_size-1 && out==0 || in==out-1)
    {
        buffer[in]=item_produced;
        empty--;
        in=(in+1)%buffer_size;
    }

    if((in+1)%(buffer_size)==out || (in==out && empty==0))
    {
    	cout<<"Buffer is Full"<<endl;
    }
    else
    {
        buffer[in]=item_produced;
        empty--;
        in=(in+1)%buffer_size;
    }
}
void consume()
{
    if(in==out && empty==buffer_size)
    {
        cout<<"Buffer is Empty\n";
    }
    else
    {
        item_consumed=buffer[out];
        buffer[out]='0';
        empty++;
        out=(out+1)%buffer_size;
        cout<<"Item Consumed: "<<item_consumed<<endl;
    }
}
void display()
{
    cout<<"Buffer is:\n";
    for(int i=0;i<buffer_size;i++)
    {
        cout<<buffer[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int ch;
    do
    {
    	cout<<"\nSelect:\n1. Produce\n2. Consume\n3. Display\n4. Exit\nEnter your choice: ";
    	cin>>ch;
        cout<<endl;
    	switch (ch)
    	{
    		case 1: produce();
            		break;
    		case 2: consume();
            		break;
    		case 3: display();
            		break;
    		case 4: cout<<"Thank You!\n";
                    break;
    		default:cout<<"Invalid Choice. Please Choose Again.\n";
        			break;
    	}
	}while(ch!=4);
}
