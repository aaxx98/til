import React from "react";
import Header from "../components/Header";
import Project from "../components/Project";
import Fade from "react-reveal/Fade";

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
                    <Fade bottom>
                        <h1>{project.title}</h1>
                        <div>{project.contents}</div>
                        <img
                            src={project.detail.image}
                            alt={project.title}
                        ></img>
                    </Fade>
                </div>
            );
        } else {
            return null;
        }
    }
}
export default Detail;
