template <class BidirectionalIterator> bool next_partial_permutation(BidirectionalIterator fi,BidirectionalIterator mi, BidirectionalIterator la){
	reverse(mi,la);
	return next_permutation(fi,la);
}

