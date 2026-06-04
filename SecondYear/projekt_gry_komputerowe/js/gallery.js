/* zLab9: skrypt galerii zarządza ładowaniem miniatur, filtrowaniem i wyświetlaniem modala */
$(document).ready(function() {
    // zLab9: dane galerii są przechowywane lokalnie w tablicy obiektów
    const galleryItems = [
        // 9 miniatur Wiedźmina
        { src: 'img/wiedzmin1.webp', sourceName: 'The Witcher', sourceUrl: 'https://witcher.com', game: 'Wiedźmin' },
        { src: 'img/wiedzmin2.jpg', sourceName: 'The Witcher', sourceUrl: 'https://witcher.com', game: 'Wiedźmin' },
        { src: 'img/wiedzmin3.jpg', sourceName: 'The Witcher', sourceUrl: 'https://witcher.com', game: 'Wiedźmin' },
        { src: 'img/wiedzmin4.jpg', sourceName: 'The Witcher', sourceUrl: 'https://witcher.com', game: 'Wiedźmin' },
        { src: 'img/wiedzmin5.jpg', sourceName: 'The Witcher', sourceUrl: 'https://witcher.com', game: 'Wiedźmin' },
        { src: 'img/wiedzmin6.jpg', sourceName: 'The Witcher', sourceUrl: 'https://witcher.com', game: 'Wiedźmin' },
        { src: 'img/wiedzmin7.jpg', sourceName: 'The Witcher', sourceUrl: 'https://witcher.com', game: 'Wiedźmin' },
        { src: 'img/wiedzmin8.webp', sourceName: 'The Witcher', sourceUrl: 'https://witcher.com', game: 'Wiedźmin' },
        { src: 'img/wiedzmin9.jpg', sourceName: 'The Witcher', sourceUrl: 'https://witcher.com', game: 'Wiedźmin' },
        // 9 miniatur Skyrim
        { src: 'img/skyrim1.webp', sourceName: 'ceneo.pl', sourceUrl: 'https://www.ceneo.pl/73353083#tab=spec', game: 'Skyrim' },
        { src: 'img/skyrim2.webp', sourceName: 'ceneo.pl', sourceUrl: 'https://www.ceneo.pl/73353083#tab=spec', game: 'Skyrim' },
        { src: 'img/skyrim3.webp', sourceName: 'nintendo.fandom.com', sourceUrl: 'https://nintendo.fandom.com/wiki/The_Elder_Scrolls_V:_Skyrim/gallery', game: 'Skyrim' },
        { src: 'img/skyrim4.webp', sourceName: 'nintendo.fandom.com', sourceUrl: 'https://nintendo.fandom.com/wiki/The_Elder_Scrolls_V:_Skyrim/gallery', game: 'Skyrim' },
        { src: 'img/skyrim5.webp', sourceName: 'nintendo.fandom.com', sourceUrl: 'https://nintendo.fandom.com/wiki/The_Elder_Scrolls_V:_Skyrim/gallery', game: 'Skyrim' },
        { src: 'img/skyrim6.jpg', sourceName: 'imperial-library.info', sourceUrl: 'https://www.imperial-library.info/content/tes5-skyrim-screenshots', game: 'Skyrim' },
        { src: 'img/skyrim7.jpg', sourceName: 'imperial-library.info', sourceUrl: 'https://www.imperial-library.info/content/tes5-skyrim-screenshots', game: 'Skyrim' },
        { src: 'img/skyrim8.jpg', sourceName: 'imperial-library.info', sourceUrl: 'https://www.imperial-library.info/content/tes5-skyrim-screenshots', game: 'Skyrim' },
        { src: 'img/skyrim9.jpg', sourceName: 'imperial-library.info', sourceUrl: 'https://www.imperial-library.info/content/tes5-skyrim-screenshots', game: 'Skyrim' },
        // 9 miniatur Celeste
        { src: 'img/celeste1.jpg', sourceName: 'instant-gaming.com', sourceUrl: 'https://www.instant-gaming.com/pl/8003-kup-celeste-pc-mac-game-steam/?srsltid=AfmBOopDXttWmL4X2BKrJEmYAq58QLEDY8cRbwI9JRan7dgmqi5YSumY', game: 'Celeste' },
        { src: 'img/celeste2.png', sourceName: 'celestegame.com', sourceUrl: 'https://www.celestegame.com/completes.html', game: 'Celeste' },
        { src: 'img/celeste3.png', sourceName: 'celestegame.com', sourceUrl: 'https://www.celestegame.com/completes.html', game: 'Celeste' },
        { src: 'img/celeste4.png', sourceName: 'celestegame.com', sourceUrl: 'https://www.celestegame.com/completes.html', game: 'Celeste' },
        { src: 'img/celeste5.png', sourceName: 'celestegame.com', sourceUrl: 'https://www.celestegame.com/', game: 'Celeste' },
        { src: 'img/celeste6.png', sourceName: 'celestegame.com', sourceUrl: 'https://www.celestegame.com/', game: 'Celeste' },
        { src: 'img/celeste7.png', sourceName: 'celestegame.com', sourceUrl: 'https://www.celestegame.com/', game: 'Celeste' },
        { src: 'img/celeste8.png', sourceName: 'celestegame.com', sourceUrl: 'https://www.celestegame.com/', game: 'Celeste' },
        { src: 'img/celeste9.png', sourceName: 'celestegame.com', sourceUrl: 'https://www.celestegame.com/completes.html', game: 'Celeste' }
    ];

    const $galleryGrid = $('.gallery-grid');
    const $buttons = $('.gallery-filter');
    const $modal = $('#galleryModal');
    const $modalImage = $('#galleryModalImage');
    const $modalSource = $('#galleryModalSource');

    function renderGallery(filter = 'all') {
        // zLab5: odświeżanie widoku galerii przy każdej zmianie filtra
        $galleryGrid.empty();

        const filteredItems = filter === 'all'
            ? galleryItems
            : galleryItems.filter(item => item.game === filter);

        // zLab5: filtrujemy i ograniczamy widok do maksymalnie 9 elementów
        const displayItems = filteredItems.slice(0, 9);

        displayItems.forEach(item => {
            /* Na potrzeby zLab2 i zLab3: generujemy pojedynczy, czysty element karty, który zostanie ułożony przez CSS Grid */
            const card = $(
                `<div class="gallery-card" role="button" tabindex="0" data-src="${item.src}" data-sourcename="${item.sourceName}" data-sourceurl="${item.sourceUrl}">
                    <img src="${item.src}" alt="${item.game}">
                </div>`
            );
            $galleryGrid.append(card);
        });
    }

    function openModal(item) {
        // zLab9: otwieranie modalnego podglądu przy użyciu jQuery
        $modalImage.attr('src', item.src).attr('alt', item.game);
        $modalSource.html("<a href='" + item.sourceUrl + "' target='_blank' rel='noopener noreferrer'>" + item.sourceName + "</a>");
        $modal.addClass('visible');
    }

    function closeModal() {
        $modal.removeClass('visible');
    }

    $buttons.on('click', function() {
        const filter = $(this).data('filter');
        $buttons.removeClass('active');
        $(this).addClass('active');
        renderGallery(filter);
    });

    $galleryGrid.on('click', '.gallery-card', function() {
        const item = {
            src: $(this).data('src'),
            sourceName: $(this).data('sourcename'),
            sourceUrl: $(this).data('sourceurl'),
            game: $(this).find('img').attr('alt')
        };
        openModal(item);
    });

    $('#galleryModalClose').on('click', closeModal);
    $('#galleryModal').on('click', function(event) {
        if (event.target === this) {
            closeModal();
        }
    });

    $(document).on('keydown', function(event) {
        if (event.key === 'Escape') {
            closeModal();
        }
    });

    renderGallery();
});