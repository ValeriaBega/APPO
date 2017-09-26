package appolab3.fac;

public class PetFactory {

    public PetFactory() {}

    //use getpet method to to get objects of type Pet
    public Pet getPet (String name, PetEnum petEnum) {
        switch (petEnum) {
            case DOG:
                return new Dog(name);
            case CAT:
                return new Cat(name);
            case FISH:
                return new Fish(name);
            default:
                throw new IllegalArgumentException("You don't have a pet like this");
        }
    }
}
