import React from "react";
import PropTypes from "prop-types";

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
export default App;
