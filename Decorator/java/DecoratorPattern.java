package Decorator.java;

/**
 * @author homo.efficio@gmail.com
 *         Created on 2017-06-18.
 */
public class DecoratorPattern {

    public static void main(String[] args) {
        AbstractPizza pizza1 = new CheeseDecorator(new ThinPizza());
        showInfo(pizza1);

        AbstractPizza pizza2 = new CheeseDecorator(new HotSauceDecorator(new CheeseDecorator(new ThinPizza())));
        showInfo(pizza2);
    }

    private static void showInfo(AbstractPizza pizza) {
        System.out.println("피자 설명: " + pizza.getDescription() + ", 가격: " + pizza.getPrice() + " 원");
    }
}

abstract class AbstractPizza {

    abstract public String getDescription();
    abstract public int getPrice();
}

class ThinPizza extends AbstractPizza {

    @Override
    public String getDescription() {
        return "씬 피자(" + getPrice() + ")";
    }

    @Override
    public int getPrice() {
        return 10;
    }
}

class CrustPizza extends AbstractPizza {

    @Override
    public String getDescription() {
        return "크러스트 피자(" + getPrice() + ")";
    }

    @Override
    public int getPrice() {
        return 15;
    }
}

abstract class PizzaDecorator extends AbstractPizza {

    protected AbstractPizza pizza;

    public PizzaDecorator(AbstractPizza pizza) {
        this.pizza = pizza;
    }

    abstract public String getDecorator();
}

class CheeseDecorator extends PizzaDecorator {

    private int price = 3;

    public CheeseDecorator(AbstractPizza pizza) {
        super(pizza);
    }

    @Override
    public String getDescription() {
        return super.pizza.getDescription() + getDecorator();
    }

    @Override
    public int getPrice() {
        return super.pizza.getPrice() + this.price;
    }

    @Override
    public String getDecorator() {
        return " | 치즈(" + this.price + ")";
    }
}

class HotSauceDecorator extends PizzaDecorator {

    private int price = 2;

    public HotSauceDecorator(AbstractPizza pizza) {
        super(pizza);
    }

    @Override
    public String getDescription() {
        return super.pizza.getDescription() + getDecorator();
    }

    @Override
    public int getPrice() {
        return super.pizza.getPrice() + this.price;
    }

    @Override
    public String getDecorator() {
        return " | 핫소스(" + this.price + ")";
    }
}