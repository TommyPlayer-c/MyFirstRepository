#ifndef __Algorithm__
#define __Algorithm__

// the thinking is similar to QuickSort
template <class BidirectionalIterator, class UnaryPredicate>
BidirectionalIterator Mypartition(BidirectionalIterator first,
                                  BidirectionalIterator last, UnaryPredicate pred)
{
    while (first != last)
    {
        // keep pointer first forward while pred is true
        while (pred(*first))
        {
            ++first;
            if (first == last)
                return first;
            // The iterator returned points to the first element of the second group.
        }

        // keep pointer last back while !pred is true
        do
        {
            --last;
            if (first == last)
                return first;
        } while (!pred(*last));

        swap(*first, *last);
        ++first;
    }
}

/*Returns an iterator to the first element in the range [first,last) for which pred returns true. 
If no such element is found, the function returns last.
*/
template <class InputIterator, class UnaryPredicate>
InputIterator Myfind_if(InputIterator first, InputIterator last, UnaryPredicate pred)
{
    while (first != last)
    {
        if (pred(*first))
            return first;
        ++first;
    }
    return last;
}

template <class InputIterator, class UnaryPredicate>
typename iterator_traits<InputIterator>::difference_type
Mycount_if(InputIterator first, InputIterator last, UnaryPredicate pred)
{
    typename iterator_traits<InputIterator>::difference_type ret = 0;
    while (first != last)
    {
        if (pred(*first))
            ++ret;
        ++first;
    }
    return ret;
}
#endif