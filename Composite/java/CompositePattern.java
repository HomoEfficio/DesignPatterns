package Composite.java;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class CompositePattern {

    public static void main(String[] args) {
        Leaf leaf1 = new Leaf("leaf1");
        Leaf leaf2 = new Leaf("leaf2");
        Leaf leaf3 = new Leaf("leaf3");
        Leaf leaf4 = new Leaf("leaf4");

        // �䱸���� ���濡 ���� ���߿� �߰�
//        Link link1 = new Link("link1");

        Composite composite1 = new Composite("List1");
        Composite composite2 = new Composite("List2");

        Composite composite3 = new Composite("List3");

        composite1.add(leaf1).add(leaf2);
        // �䱸���� ���濡 ���� ���߿� �߰�
//        composite1.add(link1);
        composite2.add(leaf3).add(leaf4);

        composite3.add(leaf1)
                  .add(composite1)
                  .add(leaf2)
                  .add(leaf3)
                  .add(composite2)
                  .add(leaf4);

        // �䱸���� ���濡 ���� ��ũ��� ������Ʈ�� �߰��Ǿ
        // �Ʒ��� �ڵ�� ������� ����
        System.out.println(composite3.getValue());
    }
}





interface Component {
    String getValue();
}

class Leaf implements Component {
    private String name;

    public Leaf(String name) {
        this.name = name;
    }

    @Override
    public String getValue() {
        return "("+ name +")";
    }
}

class Composite implements Component {
    private String name;
    private List<Component> components = new ArrayList<Component>();

    public Composite(String name) {
        this.name = name;
    }

    @Override
    public String getValue() {
        StringBuilder sb = new StringBuilder();
        sb.append(name).append(":[");
        Iterator<Component> iterator = components.iterator();
        while (iterator.hasNext()) {
            sb.append(iterator.next().getValue());
            if (iterator.hasNext()) sb.append(", ");
        }
        sb.append("]");
        return sb.toString();
    }

    public Composite add(Component component) {
        components.add(component);
        return this;
    }
}

// �䱸���� ���濡 ���� ���߿� �߰��Ǵ� �ٷΰ���
//class Link implements Component {
//    private String name;
//
//    public Link(String name) {
//        this.name = name;
//    }
//
//    @Override
//    public String getValue() {
//        return "~"+name+"~";
//    }
//}