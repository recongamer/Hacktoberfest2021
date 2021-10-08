#include <bits/stdc++.h>
using namespace std;
void array_entry(int arr[], int no_of_elements)
{
    for (int i = 0; i < no_of_elements; i++)
    {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> arr[i];
    }
}
void display_Array(int arr[], int no_of_elements)
{
    for (int i = 0; i < no_of_elements; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deletion_beginning(int arr[], int no_of_elements)
{
    for (int i = 0; i < no_of_elements; i++)
    {
        arr[i - 1] = arr[i];
    }
}
void deletion_ending(int arr[], int no_of_elements)
{
    arr[no_of_elements - 1] = arr[no_of_elements];
}
void deletion_Particular_element(int arr[], int element_to_be_deleted, int no_of_elements)
{
    int position;
    bool flag = false;
    for (int i = 0; i < no_of_elements; i++)
    {
        if (arr[i] == element_to_be_deleted)
        {
            position = i;
            flag = true;
            break;
        }
    }

    if (flag)
    {
        for (int i = position; i < no_of_elements; i++)
        {
            arr[i - 1] = arr[i];
        }
    }
    else
    {
        cout << "Element not found!!!!!!!" << endl;
    }
}

void deletion_Particular_Position(int arr[], int no_of_elements, int position)
{
    for (int i = position; i < no_of_elements; i++)
    {
        arr[i - 1] = arr[i];
    }
}

int main()
{
    int array[100], element_to_be_deleted;
    int choice, no_of_elements, position;
    do
    {
        cout << "1. Enter the elements in the array" << endl;
        cout << "2. Display the array" << endl;
        cout << "3. Deletion from the beginning" << endl;
        cout << "4. Deletion from the end" << endl;
        cout << "5. Deletion of the particular element" << endl;
        cout << "6. Deletion from the particular position" << endl;
        cout << "7. exit" << endl;
        cout << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter the number of element you want in the Array: ";
            cin >> no_of_elements;
            array_entry(array, no_of_elements);
            break;
        }
        case 2:
        {
            display_Array(array, no_of_elements);
            break;
        }
        case 3:
        {
            deletion_beginning(array, no_of_elements);
            no_of_elements -= 1;
            break;
        }
        case 4:
        {
            deletion_ending(array, no_of_elements);
            no_of_elements -= 1;
            break;
        }
        case 5:
        {
            cout << "Enter the element which you want to delete: ";
            cin >> element_to_be_deleted;
            deletion_Particular_element(array, element_to_be_deleted, no_of_elements);
            no_of_elements -= 1;
            break;
        }
        case 6:
        {
            cout << "Enter the position of the element you want to delete";
            cin >> position;
            deletion_Particular_Position(array, no_of_elements, position);
            no_of_elements -= 1;
            break;
        }
        case 7:
        {

            break;
        }

        default:
        {
            cout << "WRONG CHOICE !!!!!!!!!!!!!!!!!!!!!!!!";
            break;
        }
        }
    } while (choice != 7);
    return 0;
}