class testcase:
    def __init__(self,inp:str,out:str):
        self.inp=inp
        self.out=out
class testres:
    def __init__(self,status:str,timetaken:float):
        self.status=status
        self.timetaken=timetaken
class testrunner:
    def __init__(self,limit:float):
        self._timelimit=limit
    def run(self,code:str,testinp:str):
        raise NotImplementedError("Subclasses must implement run_test method.")
class pythonrunner(testrunner):
    def __init__(self,limit:float):
        super().__init__(limit)
    @property
    def timelimit(self):
        return self._timelimit
    @timelimit.setter
    def timelimit(self,val):
        if val<=0:
            raise ValueError("Time Limit must be positive")
        self._timelimit=val
    def run(self,code:str,testinp:str)->testres:
        print(f"[Python Runner] Running code with input: {testinp}. Limit: {self.timelimit}s")
        return testres("Accepted",0.05)
def processsubmission(runner,code:str,tc:testcase):
    return runner.run(code,tc.inp)
if __name__=='__main__':
    py_runner=pythonrunner(1.0)
    try:
        py_runner.time_limit=0.5 
        py_runner.time_limit=0.0
    except ValueError as e:
        print(f"Error caught: {e}")
    tc = testcase("10 20", "30")
    result = processsubmission(py_runner, "print(a+b)", tc)
    print(result.status)



