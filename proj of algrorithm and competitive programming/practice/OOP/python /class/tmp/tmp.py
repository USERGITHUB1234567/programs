from abc import *
class staff(ABC):
    def __init__(self,id,name,basic_salary):
        self.id=id
        self.name=name
        self.basic_salary=basic_salary
    @abstractmethod
    def cal_net_salary(self):
        pass
    def show_info(self):
        print(f"{self.id} {self.name} {self.basic_salary}")
class office_staff(staff):
    def __init__(self,id,name,basic_salary,working_day):
        super().__init__(id,name,basic_salary)
        self.working_day=working_day
    def cal_net_salary(self):
        return self.basic_salary * self.working_day / 22
class intern_staff(staff):
    def __init__(self,id,name,basic_salary,allowance):
        super().__init__(id,name,basic_salary)
        self.allowance=allowance
    def cal_net_salary(self):
        return self.allowance + self.basic_salary
a=office_staff(1,"a",1,9)
print(a.cal_net_salary())