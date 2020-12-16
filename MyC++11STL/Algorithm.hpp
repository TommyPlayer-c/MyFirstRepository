// the thinking is similar to QuickSort
template<class BidirectionalIterator, class UnaryPredicate>
 BidirectionalIterator Partition(BidirectionalIterator first,
    BidirectionalIterator last, UnaryPredicate pred)
{
    while(first != last){
        // keep pointer first forward while pred is true
        while(pred(*first)){
            ++first;
            if(first == last) return first;
            // The iterator returned points to the first element of the second group.

        }

        // keep pointer last back while !pred is true
        do{
            --last;
            if(first == last) return first;
        } while(!pred(*last));

        swap(*first, *last);
        ++first;
    }
}