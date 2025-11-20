from izzyutils.batch1.meowwers import skycake, constrained_sum_sample_pos

def angels(n):
    """Return the squares of all numbers from 1 until (inclusive) n >= 0.
    
    >>> angels(6)
    91
    >>> angels(2)
    5
    >>> [angels(n) for n in range(1,6)]
    [1, 5, 14, 30, 55]
    >>> angels(-1)
    Traceback (most recent call last):
        ...
    ValueError: n must be >= 1 baaka

    Angels of floats are OK, but the float must be an exact integer
    >>> angels(1.5)
    Traceback (most recent call last):
        ...
    ValueError: n must be an exact integer >w<

    Angels can't take numbers that are too large
    >>> angels(1e100)
    Traceback (most recent call last):
        ...
    OverflowError: n is too big!!!
    """

    import math
    if not n >= 1:
        raise ValueError("n must be >= 1 baaka")
    if math.floor(n) != n:
        raise ValueError("n must be an exact integer >w<")
    if n+1==n:
        raise OverflowError("n is too big!!!")
    
    return sum([i**2 for i in range(n+1)])


def main():
    print(constrained_sum_sample_pos(4, 420))


if __name__ == "__main__":
    skycake()
    main()
    import doctest
    doctest.testmod()
