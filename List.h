
#include <cstddef>

class List
{
	public:
		//----Constructors----
		
		List();
		List(const List& other);
		List(List&& other) noexcept;

		//----Destructor----
		
		~List();

		//----Insert methods----

		void PushBack(const int& value);
		void PushFront(const int& value);

		//----Remuve methods----
		
		void PopBack();
		void PopFront();
		void Remove(const int& value);
		void Clear();

		//----Find method----
		
		bool Find(const int& value);

		//----Check size methods----

		bool IsEmpty() const;
		size_t Size() const;

		//----Assigment operators----

		List& operator=(const List& other);
		List& operator=(List&& other);

		//----Index operator----

		int& operator[](size_t index);
		const int& operator[](size_t index) const;
		
		//----Extra methods----
		
		void Show()const;

	private:

		void Copy(const List& other);

		struct Node
		{
			int data;
			Node* next;
		};

		Node* head;




		


};
List::List()
	:head(nullptr)
{ }

List::List(const List& other)
	:head(nullptr)
{
	
}

List::List(List&& other) noexcept
	:head(other.head)
{
	other.head = nullptr;
}

List::~List()
{
	Clear();
}

void List::PushBack(const int& value)
{
	if(head == nullptr)
	{
		head = new Node{value,nullptr};
	}
	else
	{
		Node* current = head;
		 while(current->next != nullptr)
		 {
			 current = current->next;
		 }
		 current->next = new Node{value,nullptr};
	}
}


void List::Clear()
{
	while(head!= nullptr)
	{
		Node* current = head;
		head = head->next;
		delete current;
	}
}

void List::Show()const
{
	if(head == nullptr)
	{
		std::cout << "List is empty" << std::endl;

	}
	else
	{
		Node* current = head;
		while(current != nullptr)
		{
			std::cout<<current->data<<" ";
			current = current->next;
		}
		std::cout<<std::endl;
	}
}


