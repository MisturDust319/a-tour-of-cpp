// Unions are structs that can store different types of data in one memory space
// This works by allocating space for the largest data type
// Only one piece of data can occupy the Union struct at once
// The programmer is responsible for maintaining the type held in the union
// as such, open use of unions is discouraged, but
//	they can work well when encapsulated

enum Type { str, num };

// this can hold a strong OR an int
// but not both
union Value
{
	char* s;
	int i;
};

struct Entry
{
	char* name;
	Type t;
	// this is used to track what data is stored in the union
	// this is why it's good to only use encapsulated unions
	Value v;
	// uses v.s if t==str, uses v.i if t==num
	// this saves space by removing need for two values
	//	one for a string, one for an int
};

void f(Entry* p) {
	// note how you have to figure out a way to specifically address
	// the data type you want
	if (p->t == str)
		cout << p->v.s;
	else
		cout << p->v.i;
}

