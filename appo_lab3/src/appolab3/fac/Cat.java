package appolab3.fac;

public class Cat implements Pet {

    private String name;

    public Cat(String name) {
        this.name = name;
    }

    @Override
    public void doSomething() {
        System.out.println("My name is " + name + ". And I love sleeping");
    }
}
