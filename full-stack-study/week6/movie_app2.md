## 1. function Component => class Component

-   function Component
    -   function이 return하는 내용을 실행한다.

```js
function App() {
    return (
        <div>
            {foodILike.map(dish => (
                <Food
                    key={dish.id}
                    name={dish.name}
                    image={dish.image}
                    rating={dish.rating}
                />
            ))}
        </div>
    );
}
```

-   class Component는 `React.Component`을 상속받는다.

    -   `render()` 메소드가 return하는 내용을 실행한다.

    ```js
    class App extends React.Component {
        render() {
            return <h1>나는 클래스 컴포넌트</h1>;
        }
    }
    ```

### function Component와 class Component의 차이?

-   class Component에서는 state를 사용할 수 있다.
-   function Component에서는 state를 사용할 수 없어서 `useState`같은 Hook을 이용한다. class Component에서는 Hook을 사용하지 못한다.

## 2. State

state는 Object이고, Component의 data를 넣을 공간을 가지고있다.

-   state가 가지고 있는 data는 변한다.
-   state 내부의 data를 직접 변경할 수 없다.

    ```js
    // 동작하지 않는 코드
    state = {
        count: 0,
    };

    add = () => {
        this.state.count = 1;
    };
    minus = () => {
        this.state.count = -1;
    };

    render() {
        return (
            <div>
                <h1>지금 숫자는 {this.state.count}</h1>
                <button onClick={this.add}>더하기</button>
                <button onClick={this.minus}>빼기</button>
            </div>
        );
    }
    ```

    -   위 코드는 state를 변경하고`render`를 재호출하지 않으므로 화면에 변경사항이 반영되지 않는다.
    -   `setState`를 호출하여 state를 변경할 수 있다.

        ```js
        state = {
            count: 0,
        };

        add = () => {
            this.setState({ count: 1 });
        };
        minus = () => {
            this.setState({ count: -1 });
        };
        ```

        `setState`에 새로운 state를 넘겨주면 state가 재설정되고, `render`를 호출한다.

-   현재 상태를 반영하여 state를 변경하기  
    `setState`에 현재 상태를 인자로 가지는 콜백함수를 전달한다.

```js
class App extends React.Component {
    state = {
        count: 0,
    };

    add = () => {
        this.setState(cur => ({ count: cur.count + 1 }));
    };
    minus = () => {
        this.setState(cur => ({ count: cur.count - 1 }));
    };

    render() {
        return (
            <div>
                <h1>지금 숫자는 {this.state.count}</h1>
                <button onClick={this.add}>더하기</button>
                <button onClick={this.minus}>빼기</button>
            </div>
        );
    }
}
```
