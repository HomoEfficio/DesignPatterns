import abc


class AbstractPizza(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def get_description(self):
        raise NotImplementedError

    @abc.abstractmethod
    def get_price(self):
        raise NotImplementedError



class ThinPizza(AbstractPizza):
    def __init__(self):
        pass

    def get_description(self):
        return "씬 피자(%d)" % self.get_price()

    def get_price(self):
        return 10


class CrustPizza(AbstractPizza):
    def __init__(self):
        pass
        # AbstractPizza.__init__(self)

    def get_description(self):
        return "크러스트 피자(%d)" % self.get_price()

    def get_price(self):
        return 15



class PizzaDecorator(AbstractPizza, metaclass=abc.ABCMeta):
    def __init__(self, pizza):
        self.pizza = pizza

    @abc.abstractmethod
    def get_decorator(self):
        raise NotImplementedError


class CheeseDecorator(PizzaDecorator):
    price = 3

    def __init__(self, pizza):
        PizzaDecorator.__init__(self, pizza)

    def get_description(self):
        return self.pizza.get_description() + self.get_decorator()

    def get_price(self):
        return self.pizza.get_price() + self.price

    def get_decorator(self):
        return " | 치즈(%d)" % self.price


class HotSauceDecorator(PizzaDecorator):
    price = 2

    def __init__(self, pizza):
        PizzaDecorator.__init__(self, pizza)

    def get_description(self):
        return self.pizza.get_description() + self.get_decorator()

    def get_price(self):
        return self.pizza.get_price() + self.price

    def get_decorator(self):
        return " | 핫소스(%d)" % self.price



def run():
    def show_info(pizza):
        print("피자 설명: " + pizza.get_description() + ", 가격: %d" % pizza.get_price())

    pizza1 = CheeseDecorator(ThinPizza())
    show_info(pizza1)

    pizza2 = CheeseDecorator(HotSauceDecorator(CheeseDecorator(CrustPizza())))
    show_info(pizza2)

run()
