nth(Count, Item, [_|Tail]:-Count > 1,Count0 is Count - 1, nth(Count0, Item, Tail).
nth(1,Head,[Head|_]).