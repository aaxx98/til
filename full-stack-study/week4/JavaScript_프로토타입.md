# 프로토타입

자바스크립트는 Prototype 기반 언어이다. Class 문법이 ES6에 등장하긴 했지만, JavaScript의 Class 문법은 Syntactic sugar이다. [Class 문법에서 새로 등장한 생성자 선언규칙과 같이 엄격한 제약이 추가되기도](https://roy-jung.github.io/161007_is-class-only-a-syntactic-sugar/)했으나 내부적으로는 프로토타입을 기반으로 작동한다.

프로토타입을 이용하면 객체를 정의하고, 객체의 생성자, 변수, 함수를 관리할 수 있다.

JavaScript에서 `function`은 값으로 취급되는 Object이다.

`function`을 정의하면 함수 생성과 동시에 `Prototype Object`도 함께 생성되고, 객체의 prototype으로 link된다.

`function`은 Prototype Object에서 생성자(constructor)로 관리된다.

![프로토타입구조](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/522c60f3-ae0b-4150-9bd9-693170cdf4a5/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210314%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210314T145111Z&X-Amz-Expires=86400&X-Amz-Signature=5a43013c1a8e53f5e4dfe3d3e29f88619cc428eaff5608eca1e04d376ce7546b&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

```jsx
function Animal(type, name, sound) {
    this.type = type;
    this.name = name;
    this.sound = sound;
}

Animal.prototype.say = function () {
    console.log(this.sound);
};
Animal.prototype.sharedValue = 1;

const dog = new Animal("개", "멍멍이", "멍멍");
const cat = new Animal("고양이", "야옹이", "야옹");

dog.say(); //멍멍
cat.say(); //야옹

console.log(dog.sharedValue); //1
console.log(cat.sharedValue); //1
```

`new` 키워드로 객체를 생성한다. 객체 이름으로 선언한 function이 호출되면서 객체가 생성된다.

function 내부에서 프로토타입을 정의할 수 있고, function 외부에서 `[객체이름].prototype.[key]`를 이용하여 추가할 수 있다.

상속 또한 구현할 수 있다.

```jsx
function Animal(type, name, sound) {
    this.type = type;
    this.name = name;
    this.sound = sound;
}

Animal.prototype.say = function () {
    console.log(this.sound);
};
Animal.prototype.sharedValue = 1;

function Dog(name, sound) {
    Animal.call(this, "개", name, sound);
}
Dog.prototype = Animal.prototype; //Animal의 속성 상속

function Cat(name, sound) {
    Animal.call(this, "고양이", name, sound);
}
Cat.prototype = Animal.prototype; //Animal의 속성 상속

const dog = new Dog("멍멍이", "멍멍");
const cat = new Cat("야옹이", "야옹");

dog.say(); //멍멍
cat.say(); //야옹
```

위 코드에서 Dog, Cat은 Animal의 프로토타입을 복사해 갖는것으로 속성을 상속받고있다.

위 코드보다 오류가 적고 명시적인 방법의 상속은 다음과 같다.

[상속 및 오버라이딩](https://www.zerocho.com/category/JavaScript/post/59c17a58f40d2800197c65d6)

```js
var Animal = function () {};
Animal.prototype.move = function () {
    console.log("동물이 움직여요");
};

var Cat = function () {
    Animal.apply(this, arguments); // 속성 상속받는 방법
};
Cat.prototype = Object.create(Animal.prototype); // 프로토타입 상속 방법
Cat.prototype.constructor = Cat; // 버그 패치

console.log(new Animal().move()); // 동물이 움직여요
console.log(new Cat().move()); // 동물이 움직여요

Cat.prototype.move = function (sound) {
    // 오버라이딩
    console.log(sound + " 움직여요");
    return "야옹";
};

console.log(new Cat().move("살금살금")); // 살금살금 움직여요
```

부모 `Animal`의 프로토타입을 그대로 받아와서, `prototype.constructor`만 수정해 주었다.  
`Cat`의 `move()`는 오버라이드한 함수이다.
