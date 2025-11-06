"""
An exercise in overloads and their functionality.
Following along from https://www.geeksforgeeks.org/python/decorators-in-python/

Built-in overloads used:
- Self-defined (@simple_decorator, @typeof)
- @classmethod
- 


"""

def simple_decorator(func, *args, **kwargs):
    """Simple wrapper as a decorator"""
    def wrapper(*args, **kwargs):
        print(">>> glorp")
        func(*args, **kwargs)
        print(">>> fungus")
    return wrapper


@simple_decorator
def greet():
    import platform
    print(f"Hello, {platform.system()}")
greet()


def typeof(cls):
    """Works only with user-defined classes, unless it is possible to do something like (?):
    
    @typeof
    def uint64:
        // uint64 implementation remains untouched, but gains access to uint64.class_name
    """
    cls.class_name = cls.__name__
    return cls


# TODO: Figure out multiple decorators at once (?)
# @simple_decorator 
@typeof
class Person:
    pass


print(Person.class_name)

@typeof
class FaithHealer:
    @simple_decorator
    def __init__(self, name, religion, age=30):
        print(f"{name} is mayhaps of the {religion} faith")
        self.name: str = name
        self.__religion: str = religion # Private variable 
        self._age = age # Protected variable
    
    @classmethod # Built-in overload, essentially alters the *class* directly
    def set_salary(cls, amount: int) -> None:
        """Sets the salary for Mormons"""
        cls.salary = amount

    def get_salary(self) -> int | None:
        if self.__religion == "Mormon":
            return FaithHealer.salary
        else:
            return None


FaithHealer.set_salary(3000)

iHealer1 = FaithHealer("Jeremiah", "Church of the Eastern Cross")
iHealer2 = FaithHealer("Jezabehl", "Mormon")
print(iHealer1.get_salary())
print(iHealer2.get_salary())
print(iHealer1.class_name, FaithHealer.__name__)

# TODO: Figure out a way to wrap a doctest check within a decorator (?)