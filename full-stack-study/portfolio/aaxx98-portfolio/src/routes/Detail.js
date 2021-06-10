import React from "react";
import Header from "../components/Header";
import Project from "../components/Project";

class Detail extends React.Component {
    componentDidMount() {
        const { location, history } = this.props;
        if (location.state === undefined) {
            history.push("/");
        }
    }
    render() {
        const { location } = this.props;
        if (location.state) {
            const project = location.state;
            return (
                <div className="detail">
                    <h1>{project.title}</h1>
                    <div>{project.contents}</div>
                    <img src="img/stackburger_1.png" alt={project.title}></img>
                </div>
            );
        } else {
            return null;
        }
    }
}
export default Detail;
