import "./Project.css";
import { Link } from "react-router-dom";

function coloring() {
    const colors = [
        "#ffb8ce",
        "#ffc3bf",
        "#ffe26e",
        "#fffd6e",
        "#cdff8c",
        "#85ffab",
        "#abffbe",
        "#aee2e8",
        "#bdd2ff",
        "#abadff",
        "#e6c7f0",
    ];
    return colors[Math.floor(Math.random() * colors.length)];
}

function Project({ id, title, tags, date, contents, detail }) {
    return (
        <Link
            to={{
                pathname: `/project/${title}`,
                state: {
                    id,
                    title,
                    tags,
                    date,
                    contents,
                    detail,
                },
            }}
        >
            <div
                className="project"
                style={{
                    backgroundImage: `linear-gradient(rgba(255, 255, 198, 0.8), rgba(255, 255, 198, 0.8)),url(${detail.linkimg})`,
                }}
            >
                <span className="title">{title}</span>
                <span className="date">{`(${date[0]} ~ ${date[1]})`}</span>
                <div className="skills">
                    {tags.map(e => {
                        return (
                            <span
                                style={{ backgroundColor: coloring() }}
                                className="tag"
                            >
                                {e}
                            </span>
                        );
                    })}
                </div>
                <div className="contents">{contents}</div>
            </div>
        </Link>
    );
}

export default Project;
