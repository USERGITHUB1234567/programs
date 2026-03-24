class Testcase {
    constructor(inp, out) {
        this.inp=inp;
        this.out=out;
    }
}
class testres {
    constructor(status,timetaken) {
        this.status=status;
        this.timetaken=timetaken
    } 
}
class testrunner {
    constructor(limit) {
        if(new.target==testrunner) {
            throw new Error("Cannot instantiate abstract class TestRunner directly.");
        }
        this.time_limit = limit;
    }
    run(code, test_input) {
        throw new Error("Method 'run_test' must be implemented by subclasses.");
    }
}
class jsrunner extends testrunner {
    #internalCounter=0;
    constructor(limit) {
        super(limit);
    }
    run(code, testinp) {
        this.#internalCounter++;
        console.log(`[JS Runner] Running code (Attempt ${this.#internalCounter}) with input: ${testinp}`);
        return new testres("Accepted", 0.1);
    }
    getInternalCount() {
        return this.#internalCounter;
    }
}
try {
    const baseRunner=new TestRunner(1.0);
} catch (e) {
    console.error(e.message);
}
const jsRunner = new JSRunner(1.5);
jsRunner.run_test("console.log(1)", "5");
console.log(`Internal Counter: ${jsRunner.getInternalCount()}`);
console.log(`Attempt to access private: ${jsRunner.internalCounter}`); 