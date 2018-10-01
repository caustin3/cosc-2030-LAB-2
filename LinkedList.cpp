// LinkedList.cpp

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.


#include "LinkedList.h"
//#include "stdafx.h"
#include <utility>


List::List()
	: first_(NULL),size_(0),sum_(0.0)//added size_ =0 and sum_ =0
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
	this->size_ = other.size_;
	this->sum_ = other.sum_;
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}	
	//*****************************
	size_ = 0;
	sum_ = 0;
	//*****************************
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
		this->size_ = other.size_;
		this->sum_ = other.sum_;
	}

	return *this;
}

//bool List::operator==(const List &rhs){
//    if(this.size() == 0 && rhs.size() == 0){return true;}//both empty
//    if(this.size() != rhs.size()){return false;}//sizes not the same
//
//    Node * lptr = this->next_;
//    Node * rptr = rhs->next_;
//	Double lEntry = lptr->entry_;
//    Double rEntry = rptr->entry_;
//		while (lptr != NULL && rptr != NULL)
//		{
//      if(lEntry != rEntry){
//        return false;
//      }
//      lptr = lptr->next_;
//      rptr = rptr->next_;
//      lEntry = lptr->entry_;
//      rEntry = rptr->entry_;
//		} 
//
//  	return true;
//}


bool List::empty() const
{
	return first_ == NULL;	
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
	//*****************************
	size_++;
	sum_ = sum_ + x;
	//*****************************
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	//*****************************
	size_--;
	sum_ = sum_ -item;
	//*****************************
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}		
	}
	outfile << " ]";
	//*****************************
	outfile << endl << "Size: " << size_;
	outfile << endl << "sum : " << sum_;
	//*****************************
}



// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{		
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;

		
	}
	
	return first;
}

//
// //Recursive version of clone.
// //This version handles two cases, a linked structure with
// //  no Nodes, and a linked structure with one or more
// //  Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}



// Chase Austin 
//24/sep/2018
//lab 2 for COSC 2030
//my code 



int List::size()
{
	return size_;
}

double List::sum()
{	
	return sum_;
}

void List::insertAsLast(double x)
{
	if (empty())
	{
		insertAsFirst(x);
	}
	else if (!empty())
	{		
		Node * ptr = first_->next_;		
		Node * first = new Node(ptr->entry_);
		Node * last = first;
		ptr = ptr->next_;
		while (ptr != NULL )
		{		
				last->next_ = new Node(ptr->entry_);
				last = last->next_;
				ptr = ptr->next_;

		}
	}
}
//
//void List::insertAsLast(double x)
//{
//	if (!empty())
//	{
//		Node * ptr = first_->next_;
//		while (ptr != NULL)
//		{
//			ptr = ptr->next_;
//		}
//
//		if (ptr == NULL)
//		{
//			Node * last = new Node(x);
//			double beforeLast = ptr->entry_;
//			ptr = new Node(beforeLast, last);
//		}
//		sum_ = sum_ +x;
//		size_++;
//	}
//	
//}

//there was a batter way 
//double List::size()// to get the size of the linkedlist 
//{
//	double size = 0;
//	if (!empty())
//	{
//		
//		Node * ptr = first_->next_;
//		if (!empty())size++;
//		while (ptr != NULL)
//		{
//			size++;
//			ptr = ptr->next_;
//		}
//	}
//	return size;
//}
//
//double List::sum()
//{
//	double sum = 0;
//	if (!empty())
//	{
//		
//		Node * ptr = first_->next_;
//		while (ptr != NULL)
//		{
//			sum += ptr->entry_;
//			ptr = ptr->next_;
//		}
//	}
//	return sum;
//}