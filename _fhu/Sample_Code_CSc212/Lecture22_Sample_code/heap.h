
namespace heap_nspace
{
    template <class Item>
    class heap
    {
	public:

		enum {CAPACITY = 30};
		typedef size_t size_type;

		heap() {used = 0; }

		void push(const Item& entry); // add
		void pop(); // remove the highest priority entry

		size_type heap_size() const { return used;}
		size_type sorted_size() const { return sorted;}
                Item& operator[](const size_type index);

		void heap_sort();

	private:
		size_type parent(size_type k) const;
		size_type left_child(size_type k) const;
		size_type right_child(size_type k) const;

		Item data[CAPACITY];
		size_type used; //size of the heap array (data)
                size_type sorted; // size of the sorted array (data again -reused)
    };
}

#include "heap.template"
