package appolab3.cmd;

public class addition implements Command {
    /**
     * @param a - simple variable of integer type
     * @param b - simple variable of integer type
     * @return Addition of A and B
     */
    @Override
    public int compute(int a, int b) {
        return a + b;
    }
}
