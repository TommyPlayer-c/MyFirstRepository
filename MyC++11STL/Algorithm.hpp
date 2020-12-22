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
count_if(InputIterator first, InputIterator last, UnaryPredicate pred)
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

//unique函数属于STL中比较常用函数，它的功能是元素去重。即”删除”序列中所有相邻的重复元素(只保留一个)。
//此处的删除，并不是真的删除，而是指重复元素的位置被不重复的元素给占领了(详细情况，下面会讲)。
//由于它”删除”的是相邻的重复元素，所以在使用unique函数之前，一般都会将目标序列进行排序。
template <class ForwardIterator>
ForwardIterator Myunique(ForwardIterator first, ForwardIterator last)
{
    if (first == last)
        return last;

    ForwardIterator result = first;
    while (++first != last)
    {
        if (!(*result == *first)) // or: if (!pred(*result,*first)) for version (2)
            *(++result) = *first;
    }
    return ++result;
}

#endif