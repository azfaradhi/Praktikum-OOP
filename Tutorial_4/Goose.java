class Goose{
    private String name;
    private int honk;

    public Goose(){
        name = "Horrible";
        honk = 1;
    }

    public Goose(String name, int honk){
        this.name = name;
        this.honk = honk;
    }

    public void steal(String thing){
        System.out.println(name + " steals " + thing);
    }

    @Override
    public String toString(){
        String temp = "";
        temp += name + " goose says";
        for (int i = 0; i< honk; i++){
            temp+=(" honk");
        }
        return temp;
    }

public static void main(String[] args) {
  Goose g = new Goose();
  Goose h = new Goose("Sung Jin-woo", 3);
  System.out.println(g);
  System.out.println(h);
  h.steal("dagger");
}

}