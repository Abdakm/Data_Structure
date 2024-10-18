#include <iostream>
#include <cstring>
using namespace std;

class Array{
private:
    int size;
    int length;
    int *items;
public:
    Array(int arrSize){
            size = arrSize;
            length = 0;
            items = new int[arrSize];
    }
    void Fill(){
        int no_items;
        cout << "how many items you want to fill ?" << endl;
        cin >> no_items;
        if(size < no_items){
            cout << "your filling items is more than the size of your array !!" << endl;
            return;
        } else {
            for(int i=0; i < no_items; i++){
                cout << "enter your " << i << " item" << endl;
                cin >> items[i];
                length++;
            }
            cout << endl << endl;
        }
    }
    void Display(){
        cout << "Display: " ;
        for(int i=0; i < length; i++){
            cout << items[i] << '\t';
        }
        cout << endl;
    }
    int getSize(){
        return size;
    }
    int getLength(){
        return length;
    }
    int Search(int key){
        int index = -1;
        for(int i = 0; i < length ; i++){
            if(items[i] == key){
                index = i;
                break;
            }
        }
        return index;
    }
    void Append(int newItem){
        int realSize = size - length;
        if(realSize > 0){ // or size > length
            items[length] = newItem;
            length++;
        } else {
            cout << "Your array is Full!!\n" ;
        }
    }
    void Insert(int index, int newItem){
        if(size > length){
            if(index >=0 && index < size){
                for(int i = length; i > index ; i--){
                    items[i] = items[i - 1];
                }
                items[index] = newItem;
                length++;
            } else{
                cout << "Your index is wrong !!\n" ;
            }
        } else {
            cout << "Your array is Full!! \n" ;
        }
    }
    void Delete(int index){
        if(index >= 0 && index < size){
            for(int i = index; i < length-1 ; i++){
                items[i] = items[i + 1];
            }
            length--;
        } else {
            cout << "your key is our of range" << endl;
        }
    }
    void Enlarge(int newSize){
        if(newSize <= size){
            cout << "New size must be larger than old size\n" ;
            return;
        }
        int *old = items;
        items = new int[newSize];
        size = newSize;
        for(int i=0; i < length; i++){
            items[i] = old[i];
        }
        delete []old;
    }
    void Merge(Array other){
        size += other.getSize();
        int *old = items;
        items = new int[size];
        int i;
        for(i =0; i < length; i++){
            items[i] = old[i];
        }
        delete[] old;
        int j = i;
        for(int i = 0; i < other.getLength(); i++){
            items[j++] = other.items[i];
            length++;
        }
    }

};

int main()
{

    cout << "Hello This is Array ADT demo\n";
    int arraysize;
    cout << "Enter the Array Size \n";
    cin >> arraysize;
    Array myarray(arraysize);
    myarray.Fill();
    cout << "Array size = " << myarray.getSize() <<"   while length = " << myarray.getLength() <<"\n";
    myarray.Display();
   /* cout << "Enter the value to search for \n";
    int key;
    cin >> key;
    int index =   myarray.Search(key);
    if (index == -1)
        cout << "Item not found \n";
    else
        cout << "Item found @ position " << index << endl;*/
    int index;
    int newitem;
   /* cout << "Enter new item to add to the array \n";
    cin >> newitem;
    myarray.Append(newitem);
    myarray.Display();*/

    //cout << "Enter Index to delete its item \n";
    //cin >> index;
   /* cin >> newitem;
    myarray.Insert(index, newitem);*/
    //myarray.Delete(index);
    //myarray.Display();
    //cout << "Array size = " << myarray.getSize() << "   while length = " << myarray.getLength() << "\n";
    int newsize;
   /* cout << "Enter New Size\n";
    cin >> newsize;
    myarray.Enlarge(newsize);
    cout << "Array size = " << myarray.getSize() << "   while length = " << myarray.getLength() << "\n";
    myarray.Display();*/

    int newsize2;
    cout << "Enter the other array size: \n";
    cin >> newsize2;
    Array other(newsize2);
    other.Fill();
    myarray.Merge(other);
    cout << "Array size = " << myarray.getSize() << "   while length = " << myarray.getLength() << "\n";
    myarray.Display();
}


