import React from "react";
import PropTypes from "prop-types";

class App extends React.Component {
    state = {
        isLoading: true,
        seconds: 0,
    };

    componentDidMount() {
        setInterval(() => {
            if (this.state.seconds < 5)
                this.setState(cur => ({
                    isLoading: true,
                    seconds: cur.seconds + 1,
                }));
            else
                this.setState(cur => ({
                    isLoading: false,
                    seconds: 6,
                }));
        }, 1000);
    }

    render() {
        const { isLoading, seconds } = this.state;
        return <div>{isLoading ? "Loading..." + seconds : "We are Ready"}</div>;
    }
}
export default App;
