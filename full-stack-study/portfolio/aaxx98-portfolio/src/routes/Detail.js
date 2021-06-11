import React from "react";
import Header from "../components/Header";
import Project from "../components/Project";
import Fade from "react-reveal/Fade";
import "./Detail.css";

function Role({ detail }) {
    if (detail.role.length > 0) {
        return (
            <Fade bottom>
                <h2>세부 내용 및 역할</h2>
                <ul>
                    {detail.role.map(e => {
                        return <li>{e}</li>;
                    })}
                </ul>
            </Fade>
        );
    }
    return <div className="br"></div>;
}

class Detail extends React.Component {
    componentDidMount() {
        const { location, history } = this.props;
        if (location.state === undefined) {
            history.push("/");
        }
    }
    render() {
        window.scrollTo(0, 0); //페이지 진입 시 스크롤이 항상 위
        const { location } = this.props;
        if (location.state) {
            const project = location.state;
            return (
                <div className="detail">
                    <div
                        className="header"
                        style={{
                            backgroundImage: `linear-gradient(rgba(0, 0, 0, 0.8), rgba(0, 0, 0, 0.8)),url(${project.detail.linkimg})`,
                        }}
                    >
                        <h1>{project.title}</h1>
                        <p className="date">{`(${project.date[0]} ~ ${project.date[1]})`}</p>
                    </div>

                    <Fade right>
                        <div className="tags">
                            {project.tags.map(e => {
                                return <span>#{e}</span>;
                            })}
                        </div>
                    </Fade>
                    <div className="detail-contents">
                        <Fade bottom>
                            <h2>프로젝트 설명</h2>
                            <div>{project.contents}</div>
                        </Fade>

                        <Fade bottom>
                            <Role detail={project.detail}></Role>
                        </Fade>
                        <Fade bottom>
                            <span className="project-link">
                                프로젝트로 이동
                            </span>
                            <a href={project.detail.link}>
                                <i class="fab fa-github-alt fa-2x"></i>
                            </a>
                        </Fade>
                        <img
                            className="image"
                            src={project.detail.image}
                            alt={project.title}
                        ></img>
                    </div>
                </div>
            );
        } else {
            return null;
        }
    }
}
export default Detail;
