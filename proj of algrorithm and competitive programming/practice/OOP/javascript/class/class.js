class vehicle {
    constructor(manufacture,model,year) {
        this.manufacture=manufacture;
        this.model=model;
        this.year=year;
    }
    get() {return `${this.manufacture} ${this.model} manufactured in ${this.year}`;}

}
class car extends vehicle {
    constructor(manufacture,model,year,doors) {
        super(manufacture,model,year);
        this.doors=doors;
    }
    drive() {return `${this.model} is in motion`;}
    get() {return super.get()+`, this is a four wheels with ${this.doors} door(s)`;}
}
class motorcycle extends vehicle {
    constructor(manufacture,model,year,thung) {
        super(manufacture,model,year);
        this.thung=thung;
    }
    private_function() {return `${this.model} has ${this.thung}`;}
}
const mycar=new car("toyota","camry",2023,4);
console.log(mycar.get());
console.log(mycar.drive());
const mymoto=new motorcycle("a","b",2025,true)
console.log(mymoto.private_function());