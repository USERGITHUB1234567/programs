class book:
    '''page=0
    title=""
    author=""'''
    def __init__(self,p,t,a):
        self.page=p
        self.title=t
        self.author=a
    def query(self):
        return f"title:{self.title} -  Tác giả: {self.author} {self.page} trang"

my_book = book(250, "The Great Gatsby", "F. Scott Fitzgerald")
print(f"Author: {my_book.author}") 
print(my_book.query())