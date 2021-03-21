## 1. 메서드(method)

객체 내부의 함수를 메서드라고 한다. 객체의 행동을 의미한다.

```js
let user = {
    name: "John",
    age: 30,
};

user.sayHi = function () {
    alert("안녕하세요!");
};

user.sayHi(); // 안녕하세요!
```

다음은 `user`라는 객체를 생성하고, `user`에 `sayHi`라는 함수를 할당 해 준 것이다.  
`user`는 `sayHi`를 메서드로 가지게 된다.  
`user.sayHi()`처럼 객체가 가지는 메서드를 호출 할 수 있다.

```js
// 함수 선언
function sayHi() {
    alert("안녕하세요!");
}

// 선언된 함수를 메서드로 등록
user.sayHi = sayHi;
```

다음 처럼 선언 된 함수를 메서드로 등록할 수 있다.

## 2. 메서드와 `this`

메서드 내부에서 `this`는 메서드를 호출하고 있는 객체이다.

```js
let user = {
    name: "John",
    age: 30,

    sayHi() {
        // 'this'는 '현재 객체'를 나타냅니다.
        alert(this.name);
    },
};

user.sayHi(); // John
```

다음 코드에서 `user.sayHi()`를 실행하면, `sayHi` 메서드 내부의 `this`는 `user`가 된다. 따라서 `this.name`은 `user.name`인 "John"에 접근한다.

## 3. 자유로운 `this`

JavaScript에서 this 값은 런타임에 결정된다. 메서드를 호출하고 있는 객체를 가리키기 때문이다.  
함수 내부에서 this를 작성한 후 다른 객체에 메서드로 할당하는 것이 가능하다. 다음과 같은 코드로 작성할 수 있다.

```js
let user = { name: "John" };
let admin = { name: "Admin" };

function sayHi() {
    alert(this.name);
}

// 별개의 객체에서 동일한 함수를 사용함
user.f = sayHi;
admin.f = sayHi;

// 'this'는 '점(.) 앞의' 객체를 참조하기 때문에
// this 값이 달라짐
user.f(); // John  (this == user)
admin.f(); // Admin  (this == admin)

admin["f"](); // Admin (점과 대괄호는 동일하게 동작함)
```

객체 없이도 this를 가지는 함수를 호출 할 수 있지만, 이때 `this`에는 `undifined`가 할당된다.

```js
function sayHi() {
    alert(this.name);
}

sayHi(); // 에러 발생, this==undifined 이므로 this.name에 접근하면 에러가 발생한다.
```

## 4. 화살표 함수의 `this`

화살표 함수는 일반 함수와는 달리 고유한 `this`를 가지지 않는다.  
화살표 함수에서 `this`를 참조하면, 화살표 함수가 아닌 평범한 외부 함수에서의 `this`값을 참조한다.

```js
let user = {
    firstName: "보라",
    sayHi() {
        let arrow = () => alert(this.firstName);
        arrow();
    },
};

user.sayHi(); // 보라
```

다음 코드에서 화살표 함수 `arrow` 내부의 `this`는 외부함수 `sayHi`의 `this`가 된다.
