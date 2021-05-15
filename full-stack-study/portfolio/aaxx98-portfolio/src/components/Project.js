import "./Project.css";

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

function Project({ id, title, tags, date, contents }) {
    return (
        <div className="project">
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
    );
}

export default Project;
