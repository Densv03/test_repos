#include<iostream>
#include <limits>


using namespace std;

struct Link
{
	int data;
	Link* next;
}; 


void addAtFront(struct Link** head, int link_data)
{
	struct Link* newLink = new Link;
	
	newLink->data = link_data;
	newLink->next = *head;
	
	*head = newLink;
}

void addAtEnd(struct Link** head, int link_data)
{
	struct Link* newLink = new Link;
	struct Link* last = *head;
	
	newLink->data = link_data;
	newLink->next = NULL;
	
	if (*head == NULL)
	{
		*head = newLink;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newLink;
	return;
}

void insertAfter(struct Link* head, int link_data, int position)
{
	int counter = 0;
	struct Link* prev_link = head;
	while (head!=nullptr)
	{
		if (counter == position)
		{
			prev_link = head;
		}
		counter++;
		head = head->next;
	}
	
	if (prev_link == NULL)
	{
		cout << "the given previous node is required,cannot be NULL"; return;
	}

	struct Link* newLink = new Link;

	newLink->data = link_data;
	newLink->next = prev_link->next;

	prev_link->next = newLink;
}

void displayList(struct Link* head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int elementsCount(struct Link* head)
{
	int counter = 0;
	while (head != nullptr)
	{
		counter++;
		head = head->next;
	}
	return counter;
}

int maxValue(struct Link* head)
{
	int max = head->data;
	while (head != NULL)
	{
		if (max < head->data)
		{
			max = head->data;
		}
		head = head->next;
	}
	return max;
}

int minValue(struct Link* head)
{
	int min = head->data;
	while (head != NULL)
	{
		if (min > head->data)
		{
			min = head->data;
		}
		head = head->next;
	}
	return min;
}

void deleteList(struct Link** head)
{
	Link* current = *head;
	Link* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}

void deleteElement(struct Link** head_ref, int key)
{
	Link* temp = *head_ref;
	Link* prev = NULL;

	if (temp != NULL && temp->data == key)
	{
		*head_ref = temp->next; 
		delete temp;            
		return;
	}
	else
	{
		while (temp != NULL && temp->data != key)
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL)
			return;
		
		prev->next = temp->next;
		delete temp;
	}
}

void deleteElementAtPos(struct Link** head_ref, int position)
{
	if (*head_ref == NULL)
		return;

	struct Link* temp = *head_ref;
 
	if (position == 0)
	{
		*head_ref = temp->next;   
		free(temp);             
		return;
	}

	for (int i = 0; temp != NULL && i < position - 1; i++)
		temp = temp->next;
 
	if (temp == NULL || temp->next == NULL)
		return;

	struct Link* next = temp->next->next;
	free(temp->next);  
	temp->next = next; 
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	
	struct Link* head = nullptr;

	int data, choice;
	bool repeat = true;
	
	while(true){
		
		cout << "1 - Заповнити однобiчно звязний список (щоб завершити введiть N)" << endl
			<< "2 - Додати елемент на початок списку" << endl
			<< "3 - Додати елемент пiсля вказаного елементу" << endl
			<< "4 - Видалити елемент списку" << endl
			<< "5 - Видалити елемент за номером у списку" << endl
			<< "6 - Видалити список" << endl
			<< "0 - Завершити виконання" << endl;
		
		if (!cin) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		cin >> choice;
		
		switch (choice){
		case(1):
		{
			cout << "Введiть елементи: " << endl;
			while (cin >> data)
			{
				addAtEnd(&head, data);
				if (data != data)
				{
					break;
				}
				if (elementsCount(head) > 256 && elementsCount(head) < 1)
				{
					cout << "Кiлькiсть елементiв повинна бути бiльша 1 i менша 256" << endl;
					break;
				}
			}
			cout << "Кiлькiсть елементiв списку: " << elementsCount(head) << endl;
			cout << "Введенi елементи списку: " << endl;
			displayList(head);
			break;
		}
		case(2):
		{
			cout << "Введiть елемент, який хочете додати: ";
			cin >> data;
			addAtFront(&head, data);
			cout << "Ваш список: " << endl;
			displayList(head);
			break;
		}
		case(3):
		{
			int position;
			cout << "Введiть елемент, який хочете додати: ";
			cin >> data;
			cout << "Введiть номер елемента пiсля якого потрiбно додати елемент: ";
			cin >> position;
			insertAfter(head, data, position);
			cout << "Кiлькiсть елементiв списку: " << elementsCount(head) << endl;
			cout << "Ваш список: " << endl;
			displayList(head);
			break;
		}
		case(4):
		{
			int key;
			cout << "Введiть елемент, який потрiбно видалити: ";
			cin >> key;
			deleteElement(&head, key);
			cout << "Ваш список: " << endl;
			displayList(head);
			break;
		}
		case(5):
		{
			int position;
			cout << "Введiть номер елемента, який потрiбно видалити (перший елемент вважайте нульовим): ";
			cin >> position;
			deleteElementAtPos(&head, position);
			cout << "Ваш список: " << endl;
			displayList(head);
			break;
		}
		case(6):
		{
			deleteList(&head);
			break;
		}
		case(0):
		{
			break;
			exit(0);
		}
		default:
			break;
		};
	}
	
	system("pause");
	return 0;
}