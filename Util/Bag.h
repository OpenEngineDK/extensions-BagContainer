/*
    A Bag is a wrapper around any container. It does the same as the underlying container,
    with the exception that erasing elements doesn't preserve order.

    Does wrapping to avoid vtable (performence) - This way everthing will be inlined!
    Default C = vector<T> (build around this).
*/

#ifndef _BAG_H
#define _BAG_H

#include <vector>

namespace OpenEngine {
namespace Util {

template <typename T, typename C = std::vector<T> >
class Bag 
{
    // Functions
    public:
        // Get the vector stuff into our scope
        typedef typename C::iterator iterator;
        typedef typename C::const_iterator const_iterator;
        typedef typename C::reference reference;
        typedef typename C::const_reference const_reference;
        typedef typename C::allocator_type allocator_type;
        // Constructor
        Bag(){}
        Bag()(const Bag<T,C> &x){StorageContainer = x.StorageContainer}
        ~Bag(){}
        // =
        Bag<T,C> &operator=(const Bag<T,C> &x){StorageContainer = x.StorageContainer}
        // Begin
        iterator begin(){return (StorageContainer.begin());}
        const_iterator begin() const {return (StorageContainer.begin());}
        // End
        iterator end() {return (StorageContainer.end());}
        const_iterator end() const {return (StorageContainer.end());}
        // RBegin
        reverse_iterator rbegin(){return (StorageContainer.rbegin());}
        const_reverse_iterator rbegin() const {return (StorageContainer.rbegin());}
        // REnd
        reverse_iterator rend() {return (StorageContainer.rend());}
        const_reverse_iterator rend() const {return (StorageContainer.rend());}
        // Size
        size_t size() const {return (StorageContainer.size());}
        // MaxSize
        size_t max_size() const {return (StorageContainer.max_size());}
        // Resize
        void resize(size_type sz, T c = T()) {(StorageContainer.resize(sz, c));}
        // Capacity
        size_t capacity() const {return (StorageContainer.capacity());}
        // Empty
        bool empty() const {return (StorageContainer.empty());}
        // Reserve
        void reserve (size_t n) {(StorageContainer.reserve(n));}
        // Operator[]
        reference operator[] (size_t n) {return (StorageContainer[n]);}
        const_reference  operator[] (size_t n) const {return (StorageContainer[n]);}
        // At
        reference at(size_t n) {return (StorageContainer.at(n));}
        const_reference at(size_t n) const {return (StorageContainer.at(n));}
        // Front
        reference front() {return (StorageContainer.front());}
        const_reference front() const {return (StorageContainer.front());}
        // Back
        reference back() {return (StorageContainer.back());}
        const_reference back() const {return (StorageContainer.back());}
        // Assign
        void assign(size_type n, const T& u) {(StorageContainer.assign(n, u));}
        // Push_Back
        void push_back(const T &x) {StorageContainer.push_back(x);}
        // Pop_Back
        void pop_back(){StorageContainer.pop_back();}
        // Insert
        iterator insert(iterator position, const T& x) {return (StorageContainer.insert(position, x));}
        void insert(iterator position, size_type n, const T& x)  {return (StorageContainer.insert(position, n, x));}
        // Erase
        iterator erase(iterator position)
        {
            size_t Index = position - StorageContainer.begin();
            (StorageContainer.at(Index)) = (StorageContainer.back());
            StorageContainer.pop_back();
            return (StorageContainer.begin() + Index);
        }
        iterator erase(iterator first, iterator last)
        {
            size_t Index = first - StorageContainer.begin();
            size_t Index2 = last - StorageContainer.begin();
            for(size_t Loop=Index; Loop<=Index2; ++Loop)
            {
                StorageContainer.at(Loop) = (StorageContainer.back());
                StorageContainer.pop_back();        
            }
            return (StorageContainer.begin() + Index);
        }
        // Swap
        void swap(Bag<T,C>& bag) {(StorageContainer.swap(bag.StorageContainer));}
        // Clear
        void clear() {StorageContainer.clear();}
        // Get_Allocator
        allocator_type get_allocator() const  {return (StorageContainer.get_allocator());}

    // Variables
    public:
    private:
        C StorageContainer;
    protected:
};

}}
#endif
