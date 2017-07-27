const Element = class {
    constructor(name = "default") {
        this._name = name;
    }

    accept(visitor) {
        visitor(this);
    }

    doElementThing() {
        throw Error("This method should be overriden");
    }
};

const BracketElement = class extends Element {
    constructor(name) {
        super();
        this._name = name;
    }

    doElementThing() {
        return `<${this._name}>`;
    }
};

const CurlyBraceElement = class extends Element {
    constructor(name) {
        super();
        this._name = name;
    }

    doElementThing() {
        return `{${this._name}}`;
    }
};

const AsteriskElement = class extends Element {
    constructor(name) {
        super();
        this._name = name;
    }

    doElementThing() {
        return `*${this._name}*`;
    }
};

// Visitor는 어차피 함수 하나이고,
// JavaScript는 함수를 파라미터로 넘길 수 있으므로
// Java 처럼 굳이 interface를 만들 필요 없이 그냥 함수로만 작성해도 된다.
// 하지만 accept에서 형 검사를 할 수 있도록 visitor도 객체화 하는 것이 좋을 수도 있다.
const lowercaseVisitor = (element) => console.log(`ElementName: ${element.doElementThing().toLowerCase()}`);

const uppercaseVisitor = (element) => console.log(`ElementName: ${element.doElementThing().toUpperCase()}`);


(() => {
    const elements = [];
    let i;

    elements.push(new BracketElement("Bracket1"));
    elements.push(new CurlyBraceElement("CurlyBrace1"));
    elements.push(new CurlyBraceElement("CurlyBrace2"));
    elements.push(new BracketElement("Bracket2"));
    elements.push(new CurlyBraceElement("CurlyBrace3"));
    elements.push(new BracketElement("Bracket3"));
    elements.push(new BracketElement("Bracket4"));
    // 요구사항 변경으로 나중에 추가
    //elements.push(new AsteriskElement("Asterisk1"));
    elements.push(new CurlyBraceElement("CurlyBrace4"));

    console.log("========== Lowercase Visitor ==========");
    // 요구사항 변경으로 Element의 child가 새로 추가되어도
    // 아래 코드는 변하지 않음
    for(i in elements){
        elements[i].accept(lowercaseVisitor);
    }

    console.log("========== Uppercase Visitor ==========");
    // 요구사항 변경으로 Element의 child가 새로 추가되어도
    // 아래 코드는 변하지 않음
    for(i in elements){
        elements[i].accept(uppercaseVisitor);
    }
})();