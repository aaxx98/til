import React from "react";
import axios from "axios";
import PropTypes from "prop-types";
import Movie from "./Movies";

class App extends React.Component {
    state = {
        isLoading: true,
        movies: [],
    };

    getMovies = async () => {
        const {
            data: {
                data: { movies },
            },
        } = await axios.get(
            "https://yts-proxy.now.sh/list_movies.json?sort_by=rating"
        );
        this.setState({ movies, isLoading: false });
    };

    componentDidMount() {
        this.getMovies();
    }

    render() {
        const { isLoading, movies } = this.state;
        return (
            <div>
                {isLoading ? (
                    <div class="loader">
                        <span class="loader__text">Loading...</span>
                    </div>
                ) : (
                    <div class="movies">
                        {movies.map(movie => (
                            <section class="container">
                                <Movie
                                    key={movie.id}
                                    id={movie.id}
                                    year={movie.year}
                                    title={movie.title}
                                    summary={movie.summary}
                                    poster={movie.medium_cover_image}
                                />
                            </section>
                        ))}
                    </div>
                )}
            </div>
        );
    }
}
export default App;
